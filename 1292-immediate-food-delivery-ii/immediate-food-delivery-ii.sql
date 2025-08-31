with cte as(select d.*,
rank() OVER (PARTITION by(customer_id) order by order_date ) as rnk
from Delivery d
)

select  round(sum(order_date = customer_pref_delivery_date and rnk = 1) *100/ sum(rnk = 1),2) as immediate_percentage
from cte;