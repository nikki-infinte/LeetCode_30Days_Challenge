select e.employee_id , e.name , count(e2.reports_to)as reports_count , round(avg(e2.age)) as average_age
from employees e
join employees e2
on e.employee_id = e2.reports_to
group by e2.reports_to
order by e.employee_id ;