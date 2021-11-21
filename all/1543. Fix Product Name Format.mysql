# Write your MySQL query statement below
SELECT TRIM(LOWER(product_name)) AS product_name,
       DATE_FORMAT(sale_date, '%Y-%m') AS sale_date,
       COUNT(*) AS total
  FROM Sales
 GROUP BY TRIM(LOWER(product_name)),
		  DATE_FORMAT(sale_date, '%Y-%m')
 ORDER BY 1, 2;

