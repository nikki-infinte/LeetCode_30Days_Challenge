# Write your MySQL query statement below
select cust.name as Customers
from Customers cust
left join Orders ord
on cust.id = ord.customerId
where ord.customerId IS NULL ;
