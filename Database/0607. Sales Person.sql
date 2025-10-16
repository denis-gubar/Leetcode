# Write your MySQL query statement below
SELECT salesperson.name
  FROM salesperson LEFT JOIN 
        (company INNER JOIN orders
          ON company.com_id = orders.com_id
         AND company.name = 'RED')
    ON salesperson.sales_id = orders.sales_id
 WHERE company.com_id IS NULL