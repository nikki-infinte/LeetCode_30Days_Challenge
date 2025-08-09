# Using Subquery , 
-- Select e.name
-- from Employee e
-- where (
--     select count(*)
--     from Employee e2
--     where e2.managerId = e.id
-- ) >= 5 ;


# now by self join

select  e.name
from Employee e
join Employee e2
on e.id = e2.managerId
group by e.id 
having count(*) >=5;
