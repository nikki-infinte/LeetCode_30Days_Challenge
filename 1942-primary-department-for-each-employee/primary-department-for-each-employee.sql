select e.employee_id,(
    case when count(e.employee_id) = 1 then e.department_id
        else 
            (select e2.department_id
            from Employee e2
            where e2.employee_id = e.employee_id and e2.primary_flag ='Y'
            )
        end
)as department_id
from Employee e
group by e.employee_id;