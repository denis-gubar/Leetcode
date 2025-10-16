# Write your MySQL query statement below
SELECT customer_id, name
  FROM Customers
 WHERE customer_id IN (SELECT Orders.customer_id
                         FROM Orders INNER JOIN Product on Orders.product_id = Product.product_id
						WHERE Orders.order_date BETWEEN '2020-06-01' AND '2020-06-30'
						GROUP BY Orders.customer_id
					   HAVING SUM(product.price * Orders.quantity) >= 100)
   AND customer_id IN (SELECT Orders.customer_id
                         FROM Orders INNER JOIN Product on Orders.product_id = Product.product_id
						WHERE Orders.order_date BETWEEN '2020-07-01' AND '2020-07-31'
						GROUP BY Orders.customer_id
					   HAVING SUM(product.price * Orders.quantity) >= 100);