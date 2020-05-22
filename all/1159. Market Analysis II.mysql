# Write your MySQL query statement below
SELECT Users.user_id seller_id,
       MAX(CASE
         WHEN (Users.user_id, Items.item_id) IN
         (SELECT seller_id, 
                   item_id
              FROM
            (SELECT seller_id, 
                   item_id,
                   ROW_NUMBER() OVER (PARTITION by seller_id ORDER BY order_date) r_number
              FROM Orders) data
             WHERE r_number = 2) THEN 'yes'
         ELSE 'no'
       END) 2nd_item_fav_brand
  FROM Users INNER JOIN Items
    ON Users.favorite_brand = Items.item_brand
GROUP BY Users.user_id