SELECT 
    t.person_name
FROM (
    SELECT 
        person_name,
        SUM(weight) OVER (ORDER BY turn) AS total_weight,
        turn
    FROM Queue
) t
WHERE t.total_weight <= 1000
ORDER BY t.turn DESC
LIMIT 1;