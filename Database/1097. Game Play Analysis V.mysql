# Write your MySQL query statement below
SELECT install_dt,
       COUNT(*) installs,
       ROUND(COALESCE(SUM(retention) / COUNT(*), 0), 2) Day1_retention
  FROM
(SELECT install_dt,
       CASE WHEN (player_id, DATE_ADD(install_dt,
                                      INTERVAL 1 DAY))
                                      IN 
                 (SELECT player_id,
                        event_date
                   FROM Activity) THEN 1
                ELSE 0 
       END retention
FROM (           
SELECT player_id, MIN(event_date) install_dt
  FROM Activity
 GROUP BY player_id) data) data 
 GROUP BY install_dt
