-- select product_id , year as first_year , quantity ,price
-- from Sales
-- group by product_id 
-- having year = min(year);


with firstYear as(
    select product_id , min(year)as first
    from Sales
    group by product_id
)

select s.product_id ,s.year as first_year , s.quantity,s.price
from Sales s
join firstYear f
on s.product_id = f.product_id and s.year = f.first;