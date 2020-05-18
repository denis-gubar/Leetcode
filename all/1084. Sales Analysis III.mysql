# Write your MySQL query statement below
SELECT DISTINCT Product.product_id, Product.product_name
  FROM Product INNER JOIN Sales
 USING (product_id)
 WHERE Sales.sale_date BETWEEN '2019-01-01' AND '2019-03-31'
   AND Sales.product_id NOT IN
   (SELECT DISTINCT product_id
      FROM Sales
      WHERE NOT (sale_date BETWEEN '2019-01-01' AND '2019-03-31'))