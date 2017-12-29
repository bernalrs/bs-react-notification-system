module NotificationSystem = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass =
    "react-notification-system/dist/NotificationSystem";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};
