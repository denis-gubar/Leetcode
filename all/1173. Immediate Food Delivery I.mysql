# Write your MySQL query statement below
select round(100 * COALESCE(sum(case when order_date = customer_pref_delivery_date then 1 end )/
       count(*), 0), 2) as immediate_percentage  from Delivery
 