#Metodo Newton-Rapshon

#Valor inicial x0
x0=5

#Valor de presicion
delt=0.00001

#Numero de iteraciones
n=15

#Escritura de la funcion
f= function(x) 2*x**3-8*x**2+10*x-15

plot(f,-10,3,
     lwd=1,
     main="Grafica de f(x)",
     col="Red",
     xlap="X",
     ylap="Y",
     axes= TRUE,
     n=1000
     )

#Derivada funcion
df= function(x) 6*x**2-16*x

#Ciclo de iteraciones y resultados
for (i in 1:n) {
x1= x0 - (f(x0)/df(x0))
print(c(i, x0, x1)); error=abs(x1-x0)
if(error<delt){
  cat("La solucion converge en", i ,"interaciones, Raiz=",x1);
  break()
}
x0= x1
if(i>n){
  print("Maximo numero de iteraciones alcanzado");
  break()
}
}




