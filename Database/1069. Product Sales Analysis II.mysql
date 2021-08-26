# Write your MySQL query statement below
SELECT Product.product_id, SUM(Sales.quantity) total_quantity
  FROM Sales INNER JOIN Product
 USING (product_id)
GROUP BY Product.product_id