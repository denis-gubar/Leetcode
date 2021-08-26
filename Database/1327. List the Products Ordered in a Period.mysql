# Write your MySQL query statement below
SELECT Products.product_name, SUM(unit) unit
  FROM Products INNER JOIN Orders
 USING (product_id)
 WHERE CAST(order_date AS CHAR(7)) = '2020-02'
 GROUP BY Products.product_id, Products.product_name
HAVING SUM(unit) >= 100