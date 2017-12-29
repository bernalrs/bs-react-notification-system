# Reason bindings for react-notification-system

[![npm](https://img.shields.io/npm/v/bs-react-notification-system.svg)](https://www.npmjs.com/package/bs-react-notification-system)  

[Reason](https://reasonml.github.io/) bindings for [react-notification-system](https://github.com/igorprado/react-notification-system).

## Status

🚧 This is a WIP, not everything is supported yet. 🚧

Feel free to create an issue or PR if you find anything missing.

## Installation

```
yarn add bs-react-notification-system
yarn add react-notification-system@0.2.x
```

Then add `bs-react-notification-system` to `bs-dev-dependencies` in your `bsconfig.json`:

```json
{
  ...
  "bs-dev-dependencies": ["bs-react-notification-system"]
}
```

## Usage

```reason
type action =
  | AddNotification(string);

type state = {
    _notificationSystem: ref(option(ReasonReact.reactRef)),
};

let setNotificationSystemRef = (notificationRef, {ReasonReact.state}) => 
  state._notificationSystem := Js.Nullable.to_opt(notificationRef) ;

let component = ReasonReact.reducerComponent("Notifications");

let addNotification = (message, state) => {   
    switch state._notificationSystem^ {
    | None => ()
    | Some(r) => ReasonReact.refToJsObj(r)##addNotification({"message": message, "level": "success"});      
    }
};

let make = (_children) => {
    ...component,
    initialState: () => {_notificationSystem: ref(None) },
    reducer: (action, state) =>
        switch action {
            | AddNotification(message) =>  ReasonReact.SideEffects(((_) => addNotification(message, state)))
        },
    render: ({handle, reduce}) => (
    <div>             
        <ReactNotificationSystem ref=(handle(setNotificationSystemRef)) />
        <button onClick=(reduce( (_) => AddNotification("Hello"))) > (ReasonReact.stringToElement("Click")) </button> 
    </div>
  )
};
```

## Bindings

- [x] NotificationSystem

