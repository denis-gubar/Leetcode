# Write your MySQL query statement below
SELECT product_id, first_year, price, quantity
  FROM
(SELECT Product.product_id,
       MIN(Sales.year) OVER (PARTITION BY Product.product_id) first_year,
       Sales.price,
       Sales.quantity,
       Sales.year
  FROM Sales INNER JOIN Product
 USING (product_id)) data
 WHERE first_year = year