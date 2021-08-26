# Write your MySQL query statement below
SELECT product_id, price
  FROM
(SELECT product_id, 
       new_price price,
       change_date,
       MAX(change_date) OVER (PARTITION BY product_id) latest_change_date
  FROM (SELECT product_id, new_price, change_date FROM Products
 UNION ALL
 SELECT DISTINCT product_id, 10 new_price, '1970-01-01' change_date
   FROM Products) data
 WHERE change_date <= '2019-08-16') data
 WHERE change_date = latest_change_date