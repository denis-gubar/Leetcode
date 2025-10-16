# Write your MySQL query statement below
SELECT Request_at AS DAY,
       Round(SUM(IF(status = 'cancelled_by_driver' AND
                    (SELECT Banned
                       FROM Users
                      WHERE Users.Users_Id = Trips.Driver_Id) = 'No' OR
                    status = 'cancelled_by_client' AND
                    (SELECT Banned
                       FROM Users
                      WHERE Users.Users_Id = Trips.Client_Id) = 'No',
                    1,
                    0)) / COUNT(*),
             2) AS 'Cancellation Rate'
  FROM Trips
 WHERE (SELECT Banned FROM Users WHERE Users.Users_Id = Trips.Driver_Id) = 'No'
   AND (SELECT Banned FROM Users WHERE Users.Users_Id = Trips.Client_Id) = 'No'
   AND Request_at between STR_TO_DATE('2013-10-01', '%Y-%m-%d') and STR_TO_DATE('2013-10-03', '%Y-%m-%d')
 GROUP BY Request_at;
;

