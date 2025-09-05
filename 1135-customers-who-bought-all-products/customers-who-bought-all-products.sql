WITH prod AS (
    SELECT COUNT(DISTINCT product_key) AS cnt
    FROM Product
)
SELECT 
    c.customer_id
FROM Customer c
CROSS JOIN prod p   -- ensures `p.cnt` is available
GROUP BY c.customer_id, p.cnt
HAVING COUNT(DISTINCT c.product_key) = p.cnt;
