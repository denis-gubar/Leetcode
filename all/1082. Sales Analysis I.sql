# Write your MySQL query statement below
SELECT seller_id
  FROM
(SELECT seller_id,
       total_price,
       MAX(total_price) OVER () max_total_price
  FROM       
(SELECT seller_id, SUM(price) total_price
  FROM Sales
 GROUP BY seller_id) data) data
 WHERE total_price = max_total_price