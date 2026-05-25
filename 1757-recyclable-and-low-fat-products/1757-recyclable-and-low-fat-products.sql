WITH req(product_id) AS (
    SELECT product_id
    FROM Products
    WHERE low_fats = 'Y' AND recyclable = 'Y'
)

SELECT product_id
FROM req;