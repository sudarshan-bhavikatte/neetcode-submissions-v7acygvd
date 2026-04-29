-- Write your query below

select round(
        (
            select count(*)
            from delivery
            where order_date = customer_pref_delivery_date
            ) * 100.00
        /
        (
            select count(*) from delivery
            )
        ,2
        )
    as immediate_percentage

