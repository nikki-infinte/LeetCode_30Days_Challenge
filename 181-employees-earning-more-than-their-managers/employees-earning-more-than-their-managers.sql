# Write your MySQL query statement below
SELECT e1.name AS Employee
FROM Employee e1
JOIN Employee e2
ON e1.managerid = e2.id and e1.salary > e2.salary;