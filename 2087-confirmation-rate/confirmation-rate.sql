with confirmationCount as(
    select s.user_id,
    count(c.action) as total_request,
    sum(case when c.action='confirmed' then 1 else 0 end) as confirmation_req
    from Signups s
    left join Confirmations c ON s.user_id=c.user_id
    Group by s.user_id
)

select user_id,
round(coalesce(confirmation_req*1.0/total_request,0),2)as confirmation_rate
From confirmationCount;