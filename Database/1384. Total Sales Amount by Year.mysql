# Write your MySQL query statement below
SELECT CAST(Product.product_id as CHAR) product_id,
       Product.product_name,
       '2018' report_year,
       (DATEDIFF(LEAST('2018-12-31', period_end), GREATEST('2018-01-01', period_start)) + 1) * average_daily_sales total_amount
  FROM Product INNER JOIN Sales
 USING (product_id)
 WHERE GREATEST('2018-01-01', period_start) <=
       LEAST('2018-12-31', period_end)
UNION ALL
SELECT Product.product_id,
       Product.product_name,
       '2019' report_year,
       (DATEDIFF(LEAST('2019-12-31', period_end), GREATEST('2019-01-01', period_start)) + 1) * average_daily_sales total_amount
  FROM Product INNER JOIN Sales
 USING (product_id)
 WHERE GREATEST('2019-01-01', period_start) <=
       LEAST('2019-12-31', period_end)
UNION ALL
SELECT Product.product_id,
       Product.product_name,
       '2020' report_year,
       (DATEDIFF(LEAST('2020-12-31', period_end), GREATEST('2020-01-01', period_start)) + 1) * average_daily_sales total_amount
  FROM Product INNER JOIN Sales
 USING (product_id)
 WHERE GREATEST('2020-01-01', period_start) <=
       LEAST('2020-12-31', period_end)
ORDER BY 1, 3