
select s.user_id ,   
COALESCE(
  round(
    (  select count(c2.user_id)
        from Confirmations c2
        where c2.user_id = s.user_id and c2.action = 'confirmed'
    )
    /
    (   select count(c.user_id)
        from Confirmations c
        where c.user_id = s.user_id
    ) ,2 ) , 0.00)as confirmation_rate 
    
from Signups s;