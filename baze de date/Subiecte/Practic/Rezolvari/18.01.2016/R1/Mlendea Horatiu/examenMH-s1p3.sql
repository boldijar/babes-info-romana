----------------- MLENDEA HORATIU
----------------- GRUPA 224
----------------- SUBIECTUL 1
----------------- PUNCTUL 3
----------------- 18/01/2016

--- TODO: SA NU UIT SA IL COPIEZ IN VIEW !!! ---

SELECT		Clients.Name, Bills.Number, Bills.Date, SUM(BillProducts.Quantity * BillProducts.Price) AS Value
FROM		Bills
INNER JOIN	Clients
	ON	Clients.ClientID	= Bills.ClientID
INNER JOIN	BillProducts
	ON	BillProducts.BillID	= Bills.BillID
WHERE		Bills.BillID = ANY(	SELECT	BillProducts.BillID
								FROM	BillProducts
								WHERE	BillProducts.ProductID = ANY(	SELECT	Products.ProductID
																		FROM	Products
																		WHERE	Products.Name = 'Shaorma') AND
										BillProducts.Price * BillProducts.Quantity > 300)
GROUP BY	Clients.Name, Bills.Number, Bills.Date, BillProducts.Quantity, BillProducts.Price




