# Write your MySQL query statement below
SELECT Customers.Name AS Customers
  FROM Customers
  LEFT JOIN Orders
    ON Customers.Id = Orders.CustomerId
 WHERE Orders.Id IS NULL;