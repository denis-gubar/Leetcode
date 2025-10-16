# Write your MySQL query statement below
SELECT customer_id, customer_name
  FROM Customers
 WHERE customer_id in (SELECT DISTINCT customer_id FROM Orders WHERE product_name = 'A')
   AND customer_id in (SELECT DISTINCT customer_id FROM Orders WHERE product_name = 'B')
   AND customer_id NOT in (SELECT DISTINCT customer_id FROM Orders WHERE product_name = 'C')