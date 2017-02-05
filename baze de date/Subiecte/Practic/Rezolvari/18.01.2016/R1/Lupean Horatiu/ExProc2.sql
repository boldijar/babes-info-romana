ALTER PROCEDURE AdaugareProdus
	@IdFactura					int,
	@IdProdus					int,
	@NrOrdine					int,
	@Pret						money,
	@Cantitate					int
AS
BEGIN
	DECLARE	@valueToAdd						int;

	SET	@valueToAdd							= 0;

	SET NOCOUNT ON;

	-- validare date daca trebuie
	

	BEGIN TRANSACTION;


	BEGIN TRY
		
		IF EXISTS(
			SELECT	*
			FROM	ProduseFacturi AS pf
			WHERE	(@IdProdus	= pf.IdProdus) AND
					(@IdFactura	= pf.IdFactura)
		)
		BEGIN

			PRINT 'Produsul exista pe factura, se va scadea';

			SET @valueToAdd = -@Cantitate;

		END
		ELSE
		BEGIN
			
			PRINT 'Produsul nu exista pe factura, se va adauga';

			SET @valueToAdd = @Cantitate;

		END

		INSERT INTO ProduseFacturi
		(
			IdFactura,
			IdProdus,
			NrOrdine,
			Pret,
			Cantitate
		)
		VALUES
		(
			@IdFactura,
			@IdProdus,
			@NrOrdine,
			@Pret,
			@valueToAdd
		);


		PRINT 'Success';

		COMMIT TRANSACTION;

	END TRY
	BEGIN CATCH
		
		PRINT 'Transaction failed';

		ROLLBACK TRANSACTION;

	END CATCH

	
END
GO
