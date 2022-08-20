function bound(obj) {
  return {
    arch: obj.arch.bind(obj),
    homedir: obj.homedir.bind(obj),
    hostname: obj.hostname.bind(obj),
    platform: obj.platform.bind(obj),
    type: obj.type.bind(obj),
    devNull: obj.devNull,
    EOL: obj.EOL,
  };
}

var os = bound(Bun._Os());

export var {
  arch,
  homedir,
  hostname,
  platform,
  type,
  devNull,
  EOL,
} = os;

export default os;
