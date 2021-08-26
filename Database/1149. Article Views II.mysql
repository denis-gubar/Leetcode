# Write your MySQL query statement below
SELECT DISTINCT viewer_id id
  FROM Views
GROUP BY view_date, viewer_id
 HAVING COUNT(distinct article_id) > 1
 ORDER BY id