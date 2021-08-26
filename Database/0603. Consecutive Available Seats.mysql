# Write your MySQL query statement below
SELECT Main.seat_id
  FROM cinema Main
 WHERE Main.free = 1
   AND EXISTS 
       (SELECT NULL FROM cinema Neighbors
         WHERE (Main.seat_id + 1 = Neighbors.seat_id OR
               Main.seat_id - 1 = Neighbors.seat_id)
           AND Neighbors.free = 1)