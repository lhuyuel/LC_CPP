for i in *-*; do
  id="$( cut -d '-' -f 1 <<< "$i" )"; echo "$id"
  string="$( cut -d '-' -f 2- <<< "$i" )"; echo "$string"
  new=$(printf "LC%03d_$string" "$id"); #04 pad to length of 4
  echo $new;
  mv -- "$i" "$new"
done
