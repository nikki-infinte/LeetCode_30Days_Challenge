# Write your MySQL query statement below
Select e.name
from Employee e
where (
    select count(*)
    from Employee e2
    where e2.managerId = e.id
) >= 5 ;