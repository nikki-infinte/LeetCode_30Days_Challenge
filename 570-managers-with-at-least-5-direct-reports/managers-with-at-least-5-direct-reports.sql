# Using Subquery , 
-- Select e.name
-- from Employee e
-- where (
--     select count(*)
--     from Employee e2
--     where e2.managerId = e.id
-- ) >= 5 ;


# now by self join














select (s1.name) 
from Employee s1
join Employee s2
on s1.id = s2.managerId
group by (s1.id)
having count(*) >= 5