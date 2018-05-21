# Tip Calculator. This calculator uses decimals instead of floats, for
# accuracy in financial calculations.

from decimal import Decimal
meal = Decimal(input('Enter meal total: $'))
tip = Decimal(input('Enter tip percentage: '))
tip = tip * Decimal("0.01")
tip = meal * tip
total = meal + tip
print('Total is: $', total.quantize(Decimal('.01')))
