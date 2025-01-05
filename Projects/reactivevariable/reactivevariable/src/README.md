# Reactive Variable
- This Project aims at converting Java Objects into Reactive Object.
- Reactive Objects are the objects that can be watched for the state changes.
- Any object can subscribe to the state change.
- The subscription logic is executed on separate thread.


## TODO
- Subscription logic on separate thread.


## Usage
1. Wrap any Java object around Reactive Variable.
```
ReactiveVariable<Integer> rVar = new ReactiveVariable(value);
```
2. Subscribe to the change.
```
rvar.getStateObservable().subscribe(intVar->
                System.out.println("-------- Reactive Variable is updated------- " +
                        intVar.toString()));
```
3. Change the variable using ReactiveVariableService
- First way: Simple
```
@Autowired ReactiveVariableService reactiveService;
ReactiveVariable<Integer> rvar;
reactiveService.executeChanges(rvar, 3);
```
- Second Way : Uses AOP
```
@Autowired ReactiveVariableService reactiveService;
ReactiveVariable<Integer> rvar;
reactiveService.executeChanges2(rvar, 3);
```
