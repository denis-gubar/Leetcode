# Write your MySQL query statement below
SELECT ROUND(100 * SUM(immediate)/COUNT(*), 2) immediate_percentage
  FROM
(SELECT CASE
         WHEN order_date = customer_pref_delivery_date THEN 1
         ELSE 0
       END immediate
  FROM
(SELECT customer_id, 
       order_date,
       MIN(order_date) OVER (PARTITION BY customer_id) min_order_date,
       customer_pref_delivery_date
  FROM Delivery) data
 WHERE order_date = min_order_date) data