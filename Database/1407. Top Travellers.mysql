# Write your MySQL query statement below
SELECT Users.name, COALESCE(SUM(Rides.distance), 0) travelled_distance
  FROM Users LEFT JOIN Rides
    ON Users.id = Rides.user_id
 GROUP BY Users.name, Users.id
 ORDER BY 2 desc, 1