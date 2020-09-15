function Person() {
  
}
Person.prototype.name='json';
Person.prototype.age=20;
Person.prototype.say=function(){

}
var p1=new Person();
console.log(p1);

var p2=new Person();
console.log(p2);

console.log(p1.say==p2.say);