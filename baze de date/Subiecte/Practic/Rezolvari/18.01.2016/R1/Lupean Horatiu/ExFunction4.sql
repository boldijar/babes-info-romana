USE Examen;
GO

ALTER FUNCTION ExFunction4(
)
RETURNS @retTable TABLE
(
	Luna				nvarchar(10),
	NumeAgent			nvarchar(100),
	PrenumeAgent		nvarchar(100),
	ValoareTotala		money
)
AS
BEGIN
	
	INSERT INTO		@retTable
	SELECT			MONTH(fac.DataEmiteri),
					ag.Nume,
					ag.Prenume,
					SUM(pf.Cantitate * pf.Cantitate)

	FROM			ProduseFacturi AS pf
					INNER JOIN Facturi AS fac
						ON (pf.IdProdus = fac.IdFactura)
					INNER JOIN Agenti AS ag
						ON (fac.IdAgent = ag.IdAgent)

	GROUP BY		MONTH(fac.DataEmiteri),
					ag.Nume,
					ag.Prenume,
					YEAR(fac.DataEmiteri)

	ORDER BY		MONTH(fac.DataEmiteri)	ASC,
					ag.Nume					ASC;


	RETURN;

END;