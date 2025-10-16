# Write your MySQL query statement below
SELECT Invoices.invoice_id,
       Customers.customer_name,
       Invoices.price,
       COUNT(DISTINCT Contacts.contact_email) contacts_cnt,
       COALESCE(SUM(
         CASE
           WHEN contact_email in (SELECT email from Customers) THEN 1
           ELSE 0
         END), 0) trusted_contacts_cnt 
  FROM Invoices INNER JOIN Customers
    ON Invoices.user_id = Customers.customer_id
  LEFT JOIN Contacts
    ON Contacts.user_id = Invoices.user_id
 GROUP BY Invoices.invoice_id,
       Customers.customer_name,
       Invoices.price