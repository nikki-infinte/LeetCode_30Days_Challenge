select 
CONCAT(YEAR(t.trans_date), '-', LPAD(MONTH(t.trans_date), 2, '0')) as month ,
t.country,
count(t.state) as trans_count, sum(t.state ='approved') as approved_count , 
sum(t.amount) as trans_total_amount ,
sum(case when t.state = 'approved' then (t.amount) else 0 end) as approved_total_amount 
from Transactions t
group by month,t.country;