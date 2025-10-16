# Write your MySQL query statement below
SELECT Books.book_id, Books.name
  FROM Books LEFT JOIN Orders
    ON Books.book_id = Orders.book_id
   AND Orders.dispatch_date > DATE_SUB('2019-06-23', INTERVAL 1 YEAR)
 WHERE Books.available_from < DATE_SUB('2019-06-23', INTERVAL 1 MONTH)
 GROUP BY Books.book_id, Books.name
HAVING SUM(COALESCE(Orders.quantity, 0)) < 10