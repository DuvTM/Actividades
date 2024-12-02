#Metodo Secante

#Valor iniciales
x0=1; xant=0; error=0;

#Error permitido
delt=0.000001

#Numero de iteraciones
n=10

#Escritura de la funcion
f= function(x) sin(x)+cos(1-x**2)-1

plot(f,-10,3,
     lwd=1,
     main="Grafica de f(x)",
     col="Red",
     xlap="X",
     ylap="Y",
     axes= TRUE,
     n=1000
)

#Ciclo de iteraciones y resultados
for (i in 1:n) {
  numera= f(x0)*(xant-x0)
  denomi=f(xant)-f(x0)
  x1=x0-(numera/denomi)
  print(c(i, x0, xant, x1)); error=abs(x1-x0)
  
  if(error<delt){
    cat("La solucion converge en", i ,"interaciones, Raiz=",x1);
    break()
  }
  x0= x1
  if(i==n){
    print("Maximo numero de iteraciones alcanzado");
    break()
  }
}