# Write your MySQL query statement below
WITH Dates as
(SELECT DISTINCT spend_date
  FROM Spending),
Types as
(SELECT 'both' platform
UNION ALL
SELECT 'desktop' platform
UNION ALL
SELECT 'mobile' platform)
SELECT spend_date, 
       platform, 
       SUM(total_amount) total_amount,
       SUM(total_users) total_users
  FROM       
(SELECT spend_date, platform, 0 total_amount, 0 total_users
  FROM Dates CROSS JOIN Types
UNION ALL
 SELECT Dates.spend_date, 
        'mobile' platform,
        COALESCE(SUM(amount), 0) total_amount,
        COUNT(DISTINCT Main.user_id) total_users
  FROM Dates LEFT JOIN Spending Main
    ON Dates.spend_date = Main.spend_date
   AND Main.platform = 'mobile'
 WHERE NOT EXISTS (SELECT NULL FROM Spending Others
                   WHERE Main.user_id = Others.user_id
                     AND Main.spend_date = Others.spend_date
                     AND Others.platform = 'desktop')
 GROUP BY Dates.spend_date
UNION ALL
 SELECT Dates.spend_date, 
        'desktop' platform,
        COALESCE(SUM(amount), 0) total_amount,
        COUNT(DISTINCT Main.user_id) total_users
  FROM Dates LEFT JOIN Spending Main
    ON Dates.spend_date = Main.spend_date
   AND Main.platform = 'desktop'
 WHERE NOT EXISTS (SELECT NULL FROM Spending Others
                   WHERE Main.user_id = Others.user_id
                     AND Main.spend_date = Others.spend_date
                     AND Others.platform = 'mobile')
 GROUP BY Dates.spend_date					 
UNION ALL
 SELECT Dates.spend_date, 
        'both' platform,
        COALESCE(SUM(amount), 0) total_amount,
        COUNT(DISTINCT Main.user_id) total_users
  FROM Dates LEFT JOIN Spending Main
    ON Dates.spend_date = Main.spend_date
 WHERE EXISTS (SELECT NULL FROM Spending Others
                   WHERE Main.user_id = Others.user_id
                     AND Main.spend_date = Others.spend_date
                     AND Main.platform != Others.platform) 
 GROUP BY Dates.spend_date
) Data
 GROUP BY spend_date, platform

    