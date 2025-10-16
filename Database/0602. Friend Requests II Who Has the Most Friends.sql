# Write your MySQL query statement below
SELECT id, num
  FROM 
(SELECT id, num, MAX(num) OVER () max_num FROM
(SELECT id, 
        sum(cnt) num
  FROM
(SELECT requester_id id, COUNT(*) cnt
  FROM request_accepted
 GROUP BY requester_id
 UNION ALL
 SELECT accepter_id id, COUNT(*) cnt
  FROM request_accepted
 GROUP BY accepter_id) data
GROUP BY id) data) data
 WHERE num = max_num