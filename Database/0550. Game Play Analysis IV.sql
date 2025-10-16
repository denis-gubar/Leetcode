# Write your MySQL query statement below
SELECT ROUND(COALESCE(SUM(CASE WHEN (player_id, DATE_ADD(min_event_date,
                                      INTERVAL 1 DAY))
                                      IN 
                 (SELECT player_id,
                        event_date
                   FROM Activity) THEN 1
                ELSE 0 
       END) / COUNT(*), 0), 2) fraction
FROM (           
SELECT player_id, MIN(event_date) min_event_date
  FROM Activity
 GROUP BY player_id) data