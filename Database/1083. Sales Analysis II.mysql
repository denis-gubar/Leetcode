# Write your MySQL query statement below
SELECT DISTINCT Sales.buyer_id
  FROM Sales INNER JOIN Product
 USING (product_id)
 WHERE Product.product_name = 'S8'
   AND Sales.buyer_id NOT IN 
   (SELECT Sales.buyer_id
      FROM Sales INNER JOIN Product
     USING (product_id)
     WHERE Product.product_name = 'iPhone')
 