#!/usr/bin/env bash

test_dir="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

set -e

for test_num in 1 2; do
    input=${test_dir}/input${test_num}.txt
    output=${test_dir}/output${test_num}.txt
    output_expected=${test_dir}/output${test_num}.expected.txt
    
    ${test_dir}/../build/bin/TradeCategory < "${input}" > "${output}"

    if ! cmp -s "${output}" "${output_expected}"; then
        echo "Failed"
        echo diff "${output}" "${output_expected}"
        diff "${output}" "${output_expected}"
        exit 1
    fi
done

echo "Succesfull."
exit 0
