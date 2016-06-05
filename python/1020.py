
age_days = int(raw_input())
ano = age_days/365
mes = (age_days%365)/30
dias = (age_days%365)%30
print str(ano) + " ano(s)"
print str(mes) + " mes(es)"
print str(dias) +" dia(s)"

