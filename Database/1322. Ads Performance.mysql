# Write your MySQL query statement below
SELECT ad_id, 
       ROUND(CASE
                 WHEN Clicked + Viewed = 0 THEN 0
                 ELSE 100 * Clicked / (Clicked + Viewed)
             END, 2) ctr FROM
(SELECT ad_id, 
       SUM(CASE
             WHEN action = 'Clicked' THEN 1
             ELSE 0
           END) Clicked,
       SUM(CASE
             WHEN action = 'Viewed' THEN 1
             ELSE 0
           END) Viewed
           FROM Ads
GROUP BY ad_id) data
ORDER BY ctr DESC, ad_id