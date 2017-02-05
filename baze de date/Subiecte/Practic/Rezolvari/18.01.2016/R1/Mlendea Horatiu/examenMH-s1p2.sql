----------------- MLENDEA HORATIU
----------------- GRUPA 224
----------------- SUBIECTUL 1
----------------- PUNCTUL 2
----------------- 18/01/2016

CREATE PROCEDURE AddProductToBill (
	@billID		INT,
	@productID	INT,
	@number		INT,
	@price		BIGINT,
	@quantity	BIGINT)
AS
BEGIN
	DECLARE @existsBill				INT
	DECLARE @existsProduct			INT
	DECLARE @existsProductInBill	INT

	SET @existsBill				= 0
	SET @existsProduct			= 0
	SET @existsProductInBill	= 0
	
	SELECT	@existsBill=COUNT(*)
	FROM	Bills
	WHERE	Bills.BillID = @billID

	SELECT	@existsProduct=COUNT(*)
	FROM	Products
	WHERE	Products.ProductID = @productID

	SELECT	@existsProductInBill=COUNT(*)
	FROM	BillProducts
	WHERE	BillProducts.ProductID	= @productID AND
			BillProducts.BillID		= @billID
	
	IF(@existsBill = 0) BEGIN
		PRINT 'The specified bill does not exist!'
		RETURN
	END

	IF(@existsProduct = 0) BEGIN
		PRINT 'The specified product does not exist!'
		RETURN
	END

	IF(@existsProductInBill = 0) BEGIN
		INSERT INTO BillProducts VALUES(@billID, @productID, @number, @price, @quantity)
		PRINT 'Product added to bill'
	END ELSE BEGIN
		INSERT INTO BillProducts VALUES(@billID, @productID, @number, @price, -@quantity)
		PRINT 'Product added to bill with -'
	END
END